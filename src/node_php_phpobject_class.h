// A PHP object, wrapped for access by JavaScript (node/v8).
// Inspired by v8js_object_export in the v8js PHP extension.
#ifndef NODE_PHP_PHPOBJECT_CLASS_H
#define NODE_PHP_PHPOBJECT_CLASS_H

#include <nan.h>
extern "C" {
#include <main/php.h>
#include <Zend/zend.h>
}

#include "values.h" /* for objid_t */

namespace node_php_embed {

class MapperChannel;

struct node_php_phpobject {
    MapperChannel *channel;
    objid_t id;
};

v8::Local<v8::Object> node_php_phpobject_create(MapperChannel *channel, objid_t id);

/* If the given object is an instance of PhpObject, set the id field to
 * 0 (to indicate an invalid reference to a closed PHP context). */
void node_php_phpobject_maybe_neuter(v8::Local<v8::Object> obj);

}

#endif
