int __cdecl debug_type_record_enum(c1_symbol *sym)

{
  ushort uVar1;
  ushort *puVar2;
  ushort uVar3;
  short sVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  c1_u32 cVar8;
  
  puVar2 = g_cv_record_body;
  uVar1 = (ushort)g_cv_zero_attributes;
  cVar8 = ((sym->detail).cls)->debug_index;
  if (cVar8 == 0) {
    if ((sym->flags2 & 4) == 0) {
      iVar5 = debug_emit_symbol_type_2(sym);
      return iVar5;
    }
    free_list_push_124c(sym);
    sym->flags2 = sym->flags2 & 0xf7;
    iVar5 = debug_type_record_enum_fieldlist((int *)sym);
    uVar6 = debug_cv_primitive_type_index(0x13);
    *puVar2 = 0x1007;
    iVar7 = symtab_entry_count((sym->x28).enumerators);
    puVar2[1] = (ushort)iVar7;
    *(uint *)(puVar2 + 3) = uVar6;
    *(int *)(puVar2 + 5) = iVar5;
    puVar2[2] = uVar1;
    uVar3 = (((sym->detail).cls)->layout_flags3b >> 1 & 1) << 3;
    puVar2[2] = uVar3 | uVar1 & 0xfff7;
    puVar2[2] = (ushort)(((sym->detail).cls)->flags3e >> 7) << 8 | uVar3 | uVar1 & 0xfef7;
    sVar4 = debug_identifier_length_of_type((byte *)(puVar2 + 7),sym);
    cVar8 = cvserver_emit_type(sVar4 + 0xe);
    ((sym->detail).cls)->debug_index = cVar8;
    sym->type->debug_index = ((sym->detail).cls)->debug_index;
    free_list_pop_124c();
    cVar8 = ((sym->detail).cls)->debug_index;
  }
  return cVar8;
}

