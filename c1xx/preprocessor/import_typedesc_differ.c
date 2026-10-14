byte __cdecl import_typedesc_differ(void *a,void *b)

{
  byte bVar1;
  
  bVar1 = import_typedesc_equal(a,b);
  return 1 - (bVar1 != 0);
}

