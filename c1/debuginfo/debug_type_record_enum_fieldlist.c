int __cdecl debug_type_record_enum_fieldlist(c1_symbol *tag)

{
  ushort *puVar1;
  c1_symbol **members;
  int iVar2;
  c1_symbol **member_cursor;
  uint uVar3;
  size_t sVar4;
  uint uVar5;
  size_t local_1c;
  fe_symtab_iter local_14;
  ushort *field;
  
  local_1c = symtab_entry_count(tag->tag_members);
  members = mem_xmalloc(local_1c * 4);
  symtab_iterator_init(&local_14,tag->tag_members);
  member_cursor = members;
  for (sVar4 = local_1c; sVar4 != 0; sVar4 = sVar4 - 1) {
    symtab_iterator_next(&local_14);
    *member_cursor = local_14.value;
    member_cursor = member_cursor + 1;
  }
  qsort(members,local_1c,4,sym_compare_by_entity_id);
  puVar1 = g_cv_record_body;
  uVar5 = 0;
  *g_cv_record_body = 0x1203;
  if (local_1c != 0) {
    uVar3 = 0;
    tag = (c1_symbol *)members;
    do {
      field = (ushort *)(uVar3 + 2 + (int)puVar1);
      iVar2 = *(int *)tag;
      *(byte *)(iVar2 + 1) = *(byte *)(iVar2 + 1) & 0xfd;
      *field = 0x403;
      field[1] = (ushort)g_cv_zero_attributes;
      field[1] = (ushort)g_cv_zero_attributes | 3;
      uVar3 = pdb_numeric_leaf(field + 2,*(uint *)(iVar2 + 0x28),
                               (int)*(uint *)(iVar2 + 0x28) >> 0x1f);
      iVar2 = debug_identifier_length
                        ((char *)((uVar3 & 0xffff) + 4 + (int)field),
                         *(char **)(*(int *)(iVar2 + 8) + 4));
      uVar5 = uVar5 + 4 + iVar2 + uVar3;
      uVar3 = debug_type_pad_to_4((char *)((uVar5 & 0xffff) + 2 + (int)puVar1),(char)uVar5);
      uVar5 = uVar5 + uVar3;
      uVar3 = uVar5 & 0xffff;
      if (0xfafd < uVar3 + 2) {
        diag_fatal_simple(0x43);
      }
      tag = (c1_symbol *)&tag->flags4;
      local_1c = local_1c - 1;
    } while (local_1c != 0);
  }
  mem_free(members);
  iVar2 = cvserver_emit_type(uVar5 + 2);
  return iVar2;
}

