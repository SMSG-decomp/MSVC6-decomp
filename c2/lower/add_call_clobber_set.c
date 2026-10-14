void __fastcall add_call_clobber_set(c2_tuple *call)

{
  c2_fe_symbol *pcVar1;
  c2_operand *pcVar2;
  c2_operand *pcVar3;
  c2_bitset *bs;
  c2_operand *pcVar4;
  bool bVar5;
  c2_symbol *reg;
  uint32_t n;
  
  bs = bitset_new(8);
  bVar5 = true;
  if (((g_opt_dlp != 0) && (call->src->kind == '\x04')) &&
     ((c2_fe_symbol *)call->src->sym == g_dlp_profiling_sym)) {
    bVar5 = false;
  }
  if (((((g_opt_cap == 0) && (g_opt_fastcap == 0)) || (call->src->kind != '\x04')) ||
      (((pcVar1 = (c2_fe_symbol *)call->src->sym, pcVar1 != g_cap_profiling_sym &&
        (pcVar1 != g_cap_start_profiling_sym)) && (pcVar1 != g_cap_end_profiling_sym)))) && (bVar5))
  {
    reg = g_reg_symbols + 1;
    n = 1;
    do {
      pcVar4 = find_dst_clobbering_reg(call,reg);
      if ((pcVar4 == (c2_operand *)0x0) && ((1 << ((byte)n & 0x1f) & g_call_clobber_reg_mask) != 0))
      {
        bitset_set(bs,n);
      }
      reg = reg + 1;
      n = n + 1;
    } while ((int)reg < 0x107ac9d1);
  }
  if (bs->chunks == (c2_bitset_chunk *)0x0) {
    bitset_free(bs);
    return;
  }
  pcVar4 = operand_new_regset(bs);
  if ((1 << (pcVar4->kind & 0x1f) & 0xffeU) != 0) {
    if ((pcVar4->flags & 0x10) != 0) {
      pcVar4 = (c2_operand *)node_clone((c2_node *)pcVar4);
    }
    pcVar4->flags = pcVar4->flags | 0x10;
  }
  pcVar2 = call->dst;
  if (call->dst != (c2_operand *)0x0) {
    do {
      pcVar3 = pcVar2;
      pcVar2 = pcVar3->next;
    } while (pcVar3->next != (c2_operand *)0x0);
    if (pcVar3 != (c2_operand *)0x0) {
      pcVar3->next = pcVar4;
      goto LAB_1070444a;
    }
  }
  call->dst = pcVar4;
LAB_1070444a:
  if (((1 << (pcVar4->kind & 0x1f) & 0x60U) != 0) && ((pcVar4->flags11 & 0x20) == 0)) {
    pcVar2 = pcVar4->base;
    if (pcVar2 != (c2_operand *)0x0) {
      pcVar2->flags = pcVar2->flags & 0xef;
      tuple_append_src(call,pcVar2);
    }
    pcVar4 = pcVar4->index;
    if (pcVar4 != (c2_operand *)0x0) {
      pcVar4->flags = pcVar4->flags & 0xef;
      tuple_append_src(call,pcVar4);
    }
  }
  return;
}

