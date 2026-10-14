uint32_t __fastcall alias_class_for_operand(c2_operand *op,void *ctx,uint32_t dflt)

{
  uint8_t uVar1;
  c2_alias_class_cache *pcVar2;
  uint32_t uVar3;
  c2_operand *op_00;
  int iVar4;
  c2_alias_class_cache *pcVar5;
  c2_symbol *s;
  uint32_t uVar6;
  c2_symbol *base_temp;
  c2_alias_sym_info *pcVar7;
  uint32_t cls;
  c2_bitset *local_c;
  c2_symbol *local_8;
  c2_symbol *local_4;
  
  uVar1 = op->kind;
  local_c = (c2_bitset *)0x0;
  if (uVar1 == '\x06') {
    base_temp = op->base->sym;
  }
  else {
    base_temp = op->sym;
  }
  s = base_temp;
  if (base_temp->def != (c2_tuple *)0x0) {
    iVar4 = count_address_sources(base_temp,&local_4);
    if (iVar4 == 0) {
      iVar4 = alias_find_base_pointer_roots(base_temp,ctx,&local_4,&local_c);
      if (iVar4 != 0) {
        s = local_4;
        if (iVar4 != 1) {
          if (local_c != (c2_bitset *)0x0) {
            bitset_free(local_c);
            local_c = (c2_bitset *)0x0;
          }
          s = alias_find_base_pointer(base_temp);
          if ((s == (c2_symbol *)0x0) || (s == g_alias_unknown_base)) {
            if (uVar1 != '\x06') {
              return dflt;
            }
            (op->u18).reg = g_alias_unknown_base;
            return dflt;
          }
        }
        goto LAB_10769f6f;
      }
    }
    else {
      if (iVar4 == 1) {
        if (uVar1 == '\x06') {
          (op->u18).reg = local_4;
        }
        return (uint)(local_4->fe->u3e).alias_class;
      }
      for (op_00 = base_temp->def->src; op_00 != (c2_operand *)0x0; op_00 = op_00->next) {
        mark_address_taken_operand(op_00,ctx);
      }
    }
    if (uVar1 == '\x06') {
      (op->u18).reg = g_alias_unknown_base;
    }
    return dflt;
  }
LAB_10769f6f:
  if ((s->cls != '\x0e') && ((s->flags5 & 8) == 0)) {
    s = s->storage;
  }
  if (uVar1 == '\x06') {
    iVar4 = alias_offset_through_base(s,op);
    local_8 = alias_find_or_add_offset_class(s,iVar4);
    (op->u18).reg = local_8;
    uVar6 = op->type & 0xfff;
  }
  else {
    local_8 = alias_find_or_add_offset_class(s,-1);
    uVar6 = 0;
  }
  if ((s->flags5 & 8) == 0) {
    pcVar7 = (s->u30).alias_info;
    pcVar5 = pcVar7->classes;
    for (pcVar2 = pcVar5; cls = g_alias_class_count, pcVar2 != (c2_alias_class_cache *)0x0;
        pcVar2 = pcVar2->next) {
      if (((pcVar2->pointees == (c2_bitset *)dflt) && (pcVar2->key == local_8)) &&
         (pcVar2->size == uVar6)) {
        if (pcVar2 != (c2_alias_class_cache *)0x0) {
          return pcVar2->cls;
        }
        break;
      }
    }
  }
  else {
    if (local_c == (c2_bitset *)0x0) {
      local_c = symbol_overlap_alias_set(s,ctx);
    }
    pcVar7 = (s->u30).alias_info;
    pcVar5 = pcVar7->classes;
    dflt = (uint32_t)local_c;
    for (pcVar2 = pcVar5; cls = g_alias_class_count, local_c = (c2_bitset *)dflt,
        pcVar2 != (c2_alias_class_cache *)0x0; pcVar2 = pcVar2->next) {
      iVar4 = bitset_equal(pcVar2->pointees,(c2_bitset *)dflt);
      dflt = (uint32_t)local_c;
      if (((iVar4 != 0) && (pcVar2->key == local_8)) && (pcVar2->size == uVar6)) {
        uVar3 = pcVar2->cls;
        cls = g_alias_class_count;
        if (pcVar2 != (c2_alias_class_cache *)0x0) {
          bitset_free(local_c);
          return uVar3;
        }
        break;
      }
    }
  }
  g_alias_class_count = cls + 1;
  pcVar5 = alias_cache_node_new(cls,(c2_bitset *)dflt,local_8,pcVar5);
  pcVar5->size = uVar6;
  pcVar7->classes = pcVar5;
  return cls;
}

