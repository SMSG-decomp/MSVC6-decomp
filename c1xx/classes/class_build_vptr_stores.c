c1_node * __cdecl class_build_vptr_stores(c1_node *src,c1_symbol *sym)

{
  int iVar1;
  c1_vtable_slot *pcVar2;
  c1_node *pcVar3;
  c1_node *pcVar4;
  c1_vtable_vector *pcVar5;
  int iVar6;
  short sVar7;
  c1_symbol *sym_00;
  c1_type *type;
  c1_node *local_28;
  c1_vtable_vector *local_20;
  c1_vbase_vector *local_14;
  ushort zero_half;
  int local_c;
  c1_vtable_record *local_8;
  int local_4;
  
  sVar7 = 0;
  local_28 = (c1_node *)0x0;
  class_note_vtable_built(sym);
  local_4 = 0;
  local_20 = ((sym->detail).cls)->vftables;
  local_14 = ((sym->detail).cls)->vbases;
  zero_half = 0;
  pcVar5 = local_20;
  pcVar3 = local_28;
LAB_104ae94d:
  do {
    while ((local_28 = pcVar3, pcVar3 = local_28, pcVar5 == (c1_vtable_vector *)0x0 ||
           ((int)(uint)pcVar5->count <= (int)sVar7))) {
      iVar1 = vector_iterator_next((uint *)&local_14);
      if ((char)iVar1 == '\0') {
        return local_28;
      }
      local_4 = local_c;
      sVar7 = 0;
      local_20 = *(c1_vtable_vector **)(local_c + 0x14);
      pcVar5 = local_20;
    }
    iVar1 = (int)sVar7;
    sVar7 = sVar7 + 1;
    iVar6 = 0;
    local_8 = pcVar5->data[iVar1];
    do {
      if (local_8->nslots <= iVar6) goto LAB_104ae94d;
      pcVar2 = local_8->slots + iVar6;
      iVar6 = iVar6 + 1;
      if (pcVar2 == (c1_vtable_slot *)0x0) goto LAB_104ae94d;
    } while ((*(byte *)((int)pcVar2->member + -7) & 0x20) != 0x20);
    if (pcVar2 != (c1_vtable_slot *)0x0) {
      if (local_8->alt_table == (c1_symbol *)0x0) {
        sym_00 = local_8->table;
      }
      else {
        local_8->alt_used = '\x01';
        sym_00 = local_8->alt_table;
      }
      pcVar3 = tree_new_symbol_ref(sym_00,'\x01');
      pcVar4 = tree_copy_to_arena(src,g_expr_arena_index);
      type = pcVar3->type;
      iVar1 = class_vtable_vptr_offset(local_8);
      pcVar4 = tree_new_offset(pcVar4,iVar1,type);
      pcVar4 = tree_new_rvalue(pcVar4);
      pcVar3 = expr_build_builtin_binary('t',pcVar4,pcVar3);
      pcVar5 = local_20;
      if (local_28 != (c1_node *)0x0) {
        pcVar3 = tree_new_binary_typed_right('7',local_28,pcVar3);
      }
    }
  } while( true );
}

