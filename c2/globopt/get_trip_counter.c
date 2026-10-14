c2_operand * __fastcall get_trip_counter(c2_loop *loop,c2_function *fn)

{
  uint8_t *puVar1;
  c2_symbol *pcVar2;
  c2_operand *dst;
  c2_tuple *pcVar3;
  c2_operand *src;
  
  dst = g_trip_counter_operand;
  if (g_trip_counter_operand == (c2_operand *)0x0) {
    dst = operand_new_temp_sym(0x2004);
    pcVar2 = dst->sym;
    puVar1 = &(pcVar2->u30).sizeopt.width_facts;
    *puVar1 = *puVar1 | 1;
    bitset_set(g_iv_syms,pcVar2->id);
    set_preheader_insert_point(loop);
    pcVar3 = tuple_next_real(loop->guard->head);
    if (pcVar3->line != 0) {
      g_current_line_abs = fn->line_base + (uint)pcVar3->line;
      g_cur_line = pcVar3->line;
    }
    src = materialize_value_in_preheader(0x2004,loop->trip_count,g_preheader_insert_point,0);
    tuple_new(0x15b,0x2004,dst,src,tuple_insert_before,g_preheader_insert_point);
    g_trip_counter_operand = operand_claim(dst);
  }
  return dst;
}

