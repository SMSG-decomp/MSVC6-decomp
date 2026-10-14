int __thiscall
decl_compare_type_level
          (int level,c1_type *old_type,c1_type *new_type,c1_declarator *d,c1_symbol *sym_reg,
          c1_symbol *sym)

{
  byte bVar1;
  int iVar2;
  byte bVar3;
  
  iVar2 = decl_type_modifiers_compatible(d,old_type->flags,new_type->flags,sym_reg);
  if (iVar2 == 0) {
    return 0x175;
  }
  bVar1 = (byte)old_type->code;
  if ((char)bVar1 < '\0') {
    bVar3 = (byte)new_type->code;
    if ((char)bVar3 < '\0') {
      if (((bVar3 ^ bVar1) & 0x8f) != 0) {
        return 0x174;
      }
      if ((bVar1 & 0x8f) == 0x83) {
        if (((old_type->extra).cls != (new_type->extra).cls) &&
           ((level + 1 != 1 ||
            (((old_type->extra).cls != (c1_symbol *)0x0 &&
             ((new_type->extra).cls != (c1_symbol *)0x0)))))) {
          return 0x171;
        }
      }
      else if ((bVar1 & 0x83) == 0x81) {
        if ((old_type->extra).count != (new_type->extra).count) {
          decl_compare_parameter_lists((old_type->extra).count,(new_type->extra).count);
        }
      }
      if (old_type->base != new_type->base) {
        iVar2 = decl_resolve_declarator_type_fragment(level + 1,old_type->base,new_type->base,d,sym)
        ;
        return iVar2;
      }
      return 0;
    }
  }
  else if (-1 < (char)new_type->code) {
    iVar2 = type_codes_equal(old_type->code,new_type->code);
    if (iVar2 == 0) {
      return 0x173;
    }
    if (((g_compile_flags_cc & 0x200000) == 0) &&
       ((((old_type->code & 0x800) == 0 || ((new_type->code & 0x800) == 0)) &&
        ((old_type->extra).cls != (new_type->extra).cls)))) {
      return 0x173;
    }
    return 0;
  }
  return 0x28;
}

