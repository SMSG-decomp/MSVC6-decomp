char __cdecl vector_contains_type(short *v,void *item)

{
  int iVar1;
  
  iVar1 = type_set_find(v,(int)item,(int *)0x0);
  return (char)iVar1;
}

