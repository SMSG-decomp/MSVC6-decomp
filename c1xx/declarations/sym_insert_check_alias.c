c1_symbol * sym_insert_check_alias(c1_symbol *sym2)

{
  c1_function_params *params;
  byte bVar1;
  c1_symbol *pcVar2;
  ushort uVar3;
  
  bVar1 = sym2->kind & 0x1f;
  if ((bVar1 != 0x19) && (bVar1 != 0x1a)) {
    uVar3 = sym2->type->code;
    bVar1 = (byte)uVar3;
    if ((bVar1 & 0x83) == 0x81) {
      pcVar2 = sym_new_alias_record(sym2);
      return pcVar2;
    }
    uVar3 = uVar3 & 0x8f;
    if ((((uVar3 == 0x86) || (uVar3 == 0x8e)) || (((char)bVar1 < '\0' && (uVar3 == 0x84)))) &&
       (params = (sym2->type->base->extra).params, params->default_count != '\0')) {
      decl_check_missing_default_parameter(params,sym2);
    }
  }
  return sym2;
}

