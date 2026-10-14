byte * __cdecl
decorate_storage_code_dollar_a_fragment(byte *out,uint codes,uint code,uint code7f,c1_symbol *sym)

{
  void *pvVar1;
  c1_symbol *base_sym;
  char *pcVar2;
  uint uVar3;
  byte *pbVar4;
  
  *out = 0x24;
  out[1] = 0x41;
  pbVar4 = out + 2;
  if (codes != 0x24) {
    uVar3 = code;
    if (0x40 < code7f) {
      uVar3 = codes - 0x41;
    }
    if ((uVar3 & 0x80) != 0) {
      base_sym = sym_segment_record(sym);
      pbVar4 = decorate_based_code(pbVar4,0x18,base_sym);
    }
    code = uVar3 & 0x7f;
    if (code < 0x18) {
      code = uVar3 & 0x67;
    }
    if ((0x2f < code) && (code < 0x33)) {
      code = code & 0xfffffffc;
    }
    if ((0x19 < code) && (code < 0x20)) {
      code = 0x1a;
      goto LAB_104109f0;
    }
  }
  if (0x3a < code) {
    return pbVar4;
  }
LAB_104109f0:
  switch(g_decorate_storage_case_table[code]) {
  case 0:
    pbVar4 = (byte *)decorate_type_into((char *)pbVar4,
                                        (c1_type *)
                                        **(undefined4 **)
                                          (((uint)sym->type & -(uint)((sym->type->code & 0x80) != 0)
                                           ) + 8),1);
  case 1:
    pbVar4 = (byte *)decorate_function_symbol_type((char *)pbVar4,sym);
    return pbVar4;
  case 3:
    pbVar4 = (byte *)decorate_number((char *)pbVar4,(sym->detail).value);
  case 2:
    if ((*(byte *)((int)&sym->tail + 10) & 0x10) == 0) {
      pvVar1 = (void *)0x0;
    }
    else {
      pvVar1 = sym_get_attribute(sym);
    }
    pbVar4 = (byte *)decorate_number((char *)pbVar4,(uint)pvVar1);
    pbVar4 = decorate_storage_code_function_tail(pbVar4,sym);
    return pbVar4;
  case 4:
    pcVar2 = decorate_return_type((char *)pbVar4,sym->type,2);
    pbVar4 = (byte *)decorate_type_into(pcVar2,sym->type,0);
    return pbVar4;
  case 5:
    pbVar4 = (byte *)decorate_number((char *)pbVar4,(uint)(sym->x28).block_number);
    return pbVar4;
  case 6:
    pcVar2 = decorate_type_into((char *)pbVar4,sym->type,0);
    pcVar2 = decorate_vftable_for_list(pcVar2,sym);
    *pcVar2 = '@';
    return (byte *)(pcVar2 + 1);
  case 7:
    if ((*(byte *)((int)&sym->tail + 10) & 0x10) == 0) {
      pvVar1 = (void *)0x0;
    }
    else {
      pvVar1 = sym_get_attribute_15e8(sym);
    }
    pbVar4 = (byte *)decorate_number((char *)pbVar4,(uint)pvVar1);
    pbVar4 = decorate_put_A(pbVar4);
    pbVar4 = (byte *)decorate_calling_convention
                               ((char *)pbVar4,
                                -(uint)((sym->type->code & 0x80) != 0) & (uint)sym->type);
    return pbVar4;
  case 8:
    pcVar2 = decorate_scope_chain((char *)pbVar4,&((sym->tail).tparam_value)->op);
    *pcVar2 = '@';
    return (byte *)(pcVar2 + 1);
  case 9:
    return pbVar4;
  }
}

