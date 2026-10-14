byte * __cdecl decorate_storage_code(byte *out,c1_symbol *sym,c1_symbol *sym2,uint codes)

{
  byte bVar1;
  void *pvVar2;
  byte *pbVar3;
  c1_symbol *base_sym;
  char *pcVar4;
  uint uVar5;
  
  if ((codes & 0x80) != 0) {
    *out = 0x5f;
    out = out + 1;
  }
  switch(codes & 0x7f) {
  case 0x24:
    *out = 0x24;
    out = out + 1;
    *out = 0x41;
    break;
  case 0x25:
  case 0x26:
    goto switchD_10410a07_caseD_25;
  default:
    bVar1 = (byte)codes + 0x3f & 0x7f;
    if ((bVar1 < 0x1a) || (0x1f < bVar1)) {
      bVar1 = (byte)codes & 0x7f;
    }
    else {
      *out = 0x24;
      out = out + 1;
      bVar1 = bVar1 + 0x16;
    }
    *out = bVar1;
    break;
  case 0x39:
    *out = 0x24;
    out = out + 1;
    *out = 0x42;
    break;
  case 0x3a:
    *out = 0x24;
    out = out + 1;
    *out = 0x43;
  }
  out = out + 1;
switchD_10410a07_caseD_25:
  if (codes != 0x24) {
    uVar5 = codes;
    if (0x40 < (codes & 0x7f)) {
      uVar5 = codes - 0x41;
    }
    if ((uVar5 & 0x80) != 0) {
      base_sym = sym_segment_record(sym);
      out = decorate_based_code(out,0x18,base_sym);
    }
    codes = uVar5 & 0x7f;
    if (codes < 0x18) {
      codes = uVar5 & 0x67;
    }
    if ((0x2f < codes) && (codes < 0x33)) {
      codes = codes & 0xfffffffc;
    }
    if ((0x19 < codes) && (codes < 0x20)) {
      codes = 0x1a;
      goto LAB_104109f0;
    }
  }
  if (0x3a < codes) {
    return out;
  }
LAB_104109f0:
  switch(g_decorate_storage_case_table[codes]) {
  case 0:
    out = (byte *)decorate_type_into((char *)out,
                                     (c1_type *)
                                     **(undefined4 **)
                                       (((uint)sym->type & -(uint)((sym->type->code & 0x80) != 0)) +
                                       8),1);
  case 1:
    pbVar3 = (byte *)decorate_function_symbol_type((char *)out,sym);
    return pbVar3;
  case 3:
    out = (byte *)decorate_number((char *)out,(sym->detail).value);
  case 2:
    if ((*(byte *)((int)&sym->tail + 10) & 0x10) == 0) {
      pvVar2 = (void *)0x0;
    }
    else {
      pvVar2 = sym_get_attribute(sym);
    }
    pbVar3 = (byte *)decorate_number((char *)out,(uint)pvVar2);
    pbVar3 = decorate_storage_code_function_tail(pbVar3,sym);
    return pbVar3;
  case 4:
    pcVar4 = decorate_return_type((char *)out,sym->type,2);
    pbVar3 = (byte *)decorate_type_into(pcVar4,sym->type,0);
    return pbVar3;
  case 5:
    pbVar3 = (byte *)decorate_number((char *)out,(uint)(sym->x28).block_number);
    return pbVar3;
  case 6:
    pcVar4 = decorate_type_into((char *)out,sym->type,0);
    pcVar4 = decorate_vftable_for_list(pcVar4,sym);
    *pcVar4 = '@';
    return (byte *)(pcVar4 + 1);
  case 7:
    if ((*(byte *)((int)&sym->tail + 10) & 0x10) == 0) {
      pvVar2 = (void *)0x0;
    }
    else {
      pvVar2 = sym_get_attribute_15e8(sym);
    }
    pbVar3 = (byte *)decorate_number((char *)out,(uint)pvVar2);
    pbVar3 = decorate_put_A(pbVar3);
    pbVar3 = (byte *)decorate_calling_convention
                               ((char *)pbVar3,
                                -(uint)((sym->type->code & 0x80) != 0) & (uint)sym->type);
    return pbVar3;
  case 8:
    pcVar4 = decorate_scope_chain((char *)out,&((sym->tail).tparam_value)->op);
    *pcVar4 = '@';
    return (byte *)(pcVar4 + 1);
  case 9:
    return out;
  }
}

