void vector_constructor_iterator(void *array,int size,int count,void *ctor)

{
  if (-1 < count + -1) {
    do {
      (*ctor)();
      count = count + -1;
    } while (count != 0);
  }
  return;
}

