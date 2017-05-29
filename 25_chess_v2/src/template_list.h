#define define_list(type) \
\
    struct _list_##type; \
    \
    typedef struct \
    { \
        int (*is_empty)(const struct _list_##type*); \
        size_t (*size)(const struct _list_##type*); \
        const type (*front)(const struct _list_##type*); \
        void (*insert)(struct _list_##type*, type); \
        void (*push)(struct _list_##type*, type); \
        type (*pop)(struct _list_##type*); \
        type (*shift)(struct _list_##type*); \
        int find(struct _list_##type*)

    } _list_functions_##type; \
    \
    typedef struct _list_elem_##type \
    { \
        type _data*; \
        int summit
    } list_elem_##type; \
    \
    typedef struct _list_##type \
    { \
        size_t _size; \
        list_elem_##type* _first; \
        list_elem_##type* _last; \
        _list_functions_##type* _functions; \
    } List_##type; \
    \
    List_##type* new_list_##type(); \
    bool list_is_empty_##type(const List_##type* list); \
    size_t list_size_##type(const List_##type* list); \
    const type list_front_##type(const List_##type* list); \
    void list_push_front_##type(List_##type* list, type elem); \
    \
    bool list_is_empty_##type(const List_##type* list) \
    { \
        return list->_size == 0; \
    } \
    \
    size_t list_size_##type(const List_##type* list) \
    { \
        return list->_size; \
    } \
    \
    const type list_front_##type(const List_##type* list) \
    { \
        return list->_first->_data; \
    } \
    \
    void list_push_front_##type(List_##type* list, type elem) \
    { \
        ... \
    } \
    \
    _list_functions_##type _list_funcs_##type = { \
        &list_is_empty_##type, \
        &list_size_##type, \
        &list_front_##type, \
        &list_push_front_##type, \
    }; \
    \
    List_##type* new_list_##type() \
    { \
        List_##type* res = (List_##type*) malloc(sizeof(List_##type)); \
        res->_size = 0; \
        res->_first = NULL; \
        res->_functions = &_list_funcs_##type; \
        return res; \
    }

#define List(type) \
    List_##type

#define new_list(type) \
    new_list_##type()
