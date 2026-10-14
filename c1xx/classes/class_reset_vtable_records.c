void __cdecl class_reset_vtable_records(c1_symbol *cls)

{
  c1_u8 *pcVar1;
  c1_vector *pcVar2;
  c1_vbase_vector *pcVar3;
  int iVar4;
  int iVar5;
  
  ((cls->detail).cls)->layout_flags3a = ((cls->detail).cls)->layout_flags3a & 0x7f;
  pcVar1 = &((cls->detail).cls)->layout_flags3a;
  *pcVar1 = *pcVar1 & 0xbf;
  iVar4 = 8;
  do {
    pcVar2 = vector_new(0,5);
    iVar5 = iVar4 + 4;
    *(c1_vector **)((int)&((cls->detail).cls)->size + iVar4) = pcVar2;
    iVar4 = iVar5;
  } while (iVar5 < 0x10);
  ((cls->detail).cls)->vbptr_offset = 0;
  pcVar3 = (c1_vbase_vector *)vector_new(0,5);
  ((cls->detail).cls)->vbases = pcVar3;
  return;
}

