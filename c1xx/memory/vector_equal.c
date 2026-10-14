char __cdecl vector_equal(c1_vector *a,c1_vector *b)

{
  char cVar1;
  char cVar2;
  int iVar3;
  void **ppvVar4;
  void **ppvVar5;
  
  if (a->count != b->count) {
    return '\0';
  }
  iVar3 = (uint)a->count << 2;
  ppvVar4 = a->data;
  ppvVar5 = b->data;
  do {
    if (iVar3 == 0) {
      return '\x01';
    }
    iVar3 = iVar3 + -1;
    cVar2 = *(char *)ppvVar5;
    cVar1 = *(char *)ppvVar4;
    ppvVar4 = (void **)((int)ppvVar4 + 1);
    ppvVar5 = (void **)((int)ppvVar5 + 1);
  } while (cVar1 == cVar2);
  return '\0';
}

