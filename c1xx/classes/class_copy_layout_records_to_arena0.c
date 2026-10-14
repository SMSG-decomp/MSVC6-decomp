void __cdecl class_copy_layout_records_to_arena0(c1_symbol *cls)

{
  c1_vector *pcVar1;
  c1_vbase_vector *pcVar2;
  int iVar3;
  
  iVar3 = 8;
  do {
    pcVar1 = vector_copy(*(c1_vector **)((int)&((cls->detail).cls)->size + iVar3),0,
                         class_vtable_record_move_to_arena0);
    iVar3 = iVar3 + 4;
    *(c1_vector **)((cls->detail).value + -4 + iVar3) = pcVar1;
  } while (iVar3 < 0x10);
  pcVar2 = (c1_vbase_vector *)
           vector_copy((c1_vector *)((cls->detail).cls)->vbases,0,class_vbase_record_move_to_arena);
  ((cls->detail).cls)->vbases = pcVar2;
  return;
}

