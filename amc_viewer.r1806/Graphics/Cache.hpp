#ifndef GRAPHICS_CACHE
#define GRAPHICS_CACHE

#include <assert.h>
#include <string>
#include <map>

namespace Graphics {

using std::string;
using std::map;

class CachableItem {
public:
	CachableItem();
	virtual ~CachableItem();
	unsigned int refcount;
	unsigned int id;
	virtual void reload() = 0;
	bool loaded; //used during reload() shenanigans.
};

template< class CLASS >
class CacheRef {
public:
	CacheRef(CLASS *_ref = NULL) : ref(NULL) {
		set(_ref);
	}
	CacheRef(CacheRef const &other) : ref(NULL) {
		set(other.ref);
	}
	CacheRef &operator=(CacheRef const &other) {
		set(NULL);
		set(other.ref);
		return *this;
	}
	~CacheRef() {
		set(NULL);
	}
	const CLASS *operator -> () const {
		return ref;
	}
	CLASS *operator -> () {
		return ref;
	}
	void set(CLASS *_ref) {
		if (ref != NULL) {
			assert(ref->refcount > 0);
			--(ref->refcount);
		}
		ref = _ref;
		if (ref != NULL) ++(ref->refcount);
	}
	CLASS *ref;
};

class Cache {
public:
//these are for cached data providers (fonts, textures, and such):
	void add_item(string const &key, CachableItem *item);
	CachableItem *get_item(string const &key);
	//This is a reverse lookup and REALLY SLOW.
	// (be warned.)
	string const *get_key(CachableItem *item);
//this is for your application to call at reasonable points (like when you
//suspect there is a lot of cache turnover):
	void garbage_collect();
//this is for if you ever kill the opengl state
// NOTE: this means items WON'T be properly disposed of, since their GL state
// is assumed to have vanished (poof!).
// NOTE2: this function is probably not tested, nor working (blame linux and
// osx for doing GL right).
	void reload();
//for debug:
	unsigned int get_item_count() {
		return items.size();
	}
private:
	map< string, CachableItem * > items;
};

Cache &get_cache();

} //namespace Graphics

#endif //GRAPHICS_CACHE
