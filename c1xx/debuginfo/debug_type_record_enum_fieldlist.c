int __cdecl debug_type_record_enum_fieldlist(int *sym)

{
  ushort *puVar1;
  ushort uVar2;
  int *_Base;
  int iVar3;
  int *piVar4;
  uint uVar5;
  short sVar6;
  size_t sVar7;
  size_t local_1c;
  c1_symtab_iter local_14;
  ushort *enumerate;
  uint uVar8;
  
  local_1c = symtab_entry_count((c1_symtab *)sym[10]);
  _Base = mem_xmalloc(local_1c * 4);
  symtab_iterator_init(&local_14,(c1_symtab *)sym[10]);
  piVar4 = _Base;
  for (sVar7 = local_1c; sVar7 != 0; sVar7 = sVar7 - 1) {
    symtab_iterator_next(&local_14);
    *piVar4 = (int)local_14.value;
    piVar4 = piVar4 + 1;
  }
  qsort(_Base,local_1c,4,sym_compare_by_entity_id);
  puVar1 = g_cv_record_body;
  uVar8 = 0;
  sVar6 = 0;
  *g_cv_record_body = 0x1203;
  if (local_1c != 0) {
    uVar5 = 0;
    sym = _Base;
    do {
      enumerate = (ushort *)(uVar5 + 2 + (int)puVar1);
      iVar3 = *sym;
      *(byte *)(iVar3 + 2) = *(byte *)(iVar3 + 2) & 0xf7;
      *enumerate = 0x403;
      enumerate[1] = (ushort)g_cv_zero_attributes;
      enumerate[1] = (ushort)g_cv_zero_attributes | 3;
      uVar2 = pdb_numeric_leaf(enumerate + 2,*(uint *)(iVar3 + 0x28),
                               (int)*(uint *)(iVar3 + 0x28) >> 0x1f);
      iVar3 = debug_identifier_length
                        ((byte *)(uVar2 + 4 + (int)enumerate),*(char **)(*(int *)(iVar3 + 8) + 4));
      uVar8 = uVar8 + 4 + iVar3 + (uint)uVar2;
      uVar5 = debug_type_pad_to_4((char *)((uVar8 & 0xffff) + 2 + (int)puVar1),(char)uVar8);
      uVar8 = uVar8 + uVar5;
      sVar6 = (short)uVar8;
      uVar5 = uVar8 & 0xffff;
      if (0xfafd < uVar5 + 2) {
        diag_fatal_simple(0x43);
      }
      sym = sym + 1;
      local_1c = local_1c - 1;
    } while (local_1c != 0);
  }
  mem_free(_Base);
  iVar3 = cvserver_emit_type(sVar6 + 2);
  return iVar3;
}

