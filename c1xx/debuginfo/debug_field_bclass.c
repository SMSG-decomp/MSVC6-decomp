ushort __cdecl debug_field_bclass(int pass,int base,c1_symbol *sym,ushort *out)

{
  ushort uVar1;
  
  if (pass == 1) {
    sym_ensure_debug_type(sym);
    return 0;
  }
  *out = 0x1400;
  uVar1 = debug_member_field_attributes((c1_symbol *)base);
  out[1] = uVar1;
  *(c1_u32 *)(out + 2) = sym->type->debug_index;
  uVar1 = pdb_numeric_leaf(out + 4,*(uint *)(base + 0x14),(int)*(uint *)(base + 0x14) >> 0x1f);
  return uVar1 + 8;
}

