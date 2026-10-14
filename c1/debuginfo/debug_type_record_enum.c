c1_u32 __cdecl debug_type_record_enum(c1_symbol *tag)

{
  ushort uVar1;
  ushort *puVar2;
  c1_u32 cVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  c1_symbol_x2c cVar7;
  c1_symbol_cell *pcVar8;
  
  puVar2 = g_cv_record_body;
  uVar1 = (ushort)g_cv_zero_attributes;
  pcVar8 = (tag->x2c).references;
  if (pcVar8 == (c1_symbol_cell *)0x0) {
    if ((tag->flags1 & 1) == 0) {
      cVar3 = debug_type_record_enum_forward(tag);
      return cVar3;
    }
    free_list_push_124c(tag);
    tag->flags1 = tag->flags1 & 0xfd;
    iVar4 = debug_type_record_enum_fieldlist(tag);
    iVar5 = debug_cv_primitive_type_index(0x13);
    *puVar2 = 0x1007;
    iVar6 = symtab_entry_count(tag->tag_members);
    puVar2[1] = (ushort)iVar6;
    *(int *)(puVar2 + 3) = iVar5;
    *(int *)(puVar2 + 5) = iVar4;
    puVar2[2] = uVar1;
    puVar2[2] = (ushort)((tag->tag_alignment & 0x200) >> 6) | uVar1 & 0xfff7;
    iVar4 = debug_put_symbol_name((char *)(puVar2 + 7),tag);
    cVar7 = (c1_symbol_x2c)cvserver_emit_type(iVar4 + 0xe);
    tag->x2c = cVar7;
    tag->type->debug_index = (c1_u32)cVar7;
    free_list_pop_124c();
    pcVar8 = (tag->x2c).references;
  }
  return (c1_u32)pcVar8;
}

