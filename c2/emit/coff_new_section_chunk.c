void * __fastcall coff_new_section_chunk(int a,int b)

{
  int *piVar1;
  c2_coff_chunk *pcVar2;
  
  piVar1 = (*g_coff_alloc_fn)(0x18);
  pcVar2 = coff_alloc_chunk();
  pcVar2->next = pcVar2;
  piVar1[1] = b;
  piVar1[5] = (int)pcVar2;
  *piVar1 = a;
  piVar1[2] = 0;
  piVar1[3] = 0;
  piVar1[4] = 0;
  return piVar1;
}

