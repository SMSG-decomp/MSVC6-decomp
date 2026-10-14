char __cdecl vector_contains(c1_vector *v,void *item)

{
  int iVar1;
  short sVar2;
  
  sVar2 = 0;
  while ((v != (c1_vector *)0x0 && (iVar1 = (int)sVar2, iVar1 < (int)(uint)v->count))) {
    sVar2 = sVar2 + 1;
    if (v->data[iVar1] == item) {
      return '\x01';
    }
  }
  return '\0';
}

