uint32_t __fastcall
alias_class_for_memory_base(c2_symbol *base_temp,c2_bitset *mask,uint32_t dflt,c2_block *block)

{
  c2_operand *op;
  c2_symbol *pcVar1;
  int iVar2;
  uint32_t uVar3;
  c2_symbol *pcVar4;
  c2_alias_sym_info *pcVar5;
  c2_alias_class_cache *pcVar6;
  c2_bitset *local_8;
  c2_symbol *local_4;
  
  local_8 = (c2_bitset *)0x0;
  if (base_temp->def == (c2_tuple *)0x0) {
LAB_1075281a:
    if ((base_temp->flags5 & 8) != 0) {
      uVar3 = alias_class_for_symbol_set(base_temp,local_8,mask,block);
      return uVar3;
    }
    return dflt;
  }
  iVar2 = count_address_sources(base_temp,&local_4);
  if (iVar2 != 0) {
    if (iVar2 == 1) {
      return (uint)(local_4->fe->u3e).alias_class;
    }
    for (op = base_temp->def->src; op != (c2_operand *)0x0; op = op->next) {
      mark_address_taken_operand(op,mask);
    }
    return dflt;
  }
  iVar2 = alias_find_base_pointer_roots(base_temp,mask,&local_4,&local_8);
  if (iVar2 != 0) {
    if (iVar2 != -1) {
      base_temp = local_4;
      if (iVar2 != 1) {
        pcVar4 = arena_alloc(4,0x54);
        pcVar1 = pcVar4;
        pcVar4->order_next = g_alias_synth_class_symbols;
        g_alias_synth_class_symbols = pcVar1;
        pcVar5 = arena_alloc(4,0x14);
        uVar3 = g_alias_class_count;
        (pcVar4->u30).alias_info = pcVar5;
        pcVar6 = alias_cache_node_new(uVar3,local_8,block,(c2_alias_class_cache *)0x0);
        pcVar5->classes = pcVar6;
        uVar3 = g_alias_class_count;
        g_alias_class_count = g_alias_class_count + 1;
        return uVar3;
      }
      goto LAB_1075281a;
    }
    if (local_8 != (c2_bitset *)0x0) {
      pcVar4 = arena_alloc(4,0x54);
      pcVar1 = pcVar4;
      pcVar4->order_next = g_alias_synth_class_symbols;
      g_alias_synth_class_symbols = pcVar1;
      pcVar5 = arena_alloc(4,0x14);
      uVar3 = g_alias_class_count;
      (pcVar4->u30).alias_info = pcVar5;
      pcVar6 = alias_cache_node_new(uVar3,local_8,block,(c2_alias_class_cache *)0x0);
      pcVar5->classes = pcVar6;
      (pcVar4->u34).refs = dflt;
      uVar3 = g_alias_class_count;
      g_alias_class_count = g_alias_class_count + 1;
      return uVar3;
    }
  }
  return dflt;
}

