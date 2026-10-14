c1_vector_iterator * __cdecl vector_iterator_init(c1_vector_iterator *it,void *vector)

{
  it->vector = vector;
  it->index = 0;
  return it;
}

