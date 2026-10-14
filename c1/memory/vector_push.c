void __cdecl vector_push(fe_vector *v,void *item)

{
  if (v->count == v->capacity) {
    vector_grow(v);
  }
  v->data[v->count] = item;
  v->count = v->count + 1;
  return;
}

