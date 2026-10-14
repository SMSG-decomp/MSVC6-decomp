void __fastcall reader_tls_address(c2_reader_cell *cell)

{
  byte bVar1;
  c2_operand *src2;
  c2_operand *pcVar2;
  c2_tuple *pcVar3;
  c2_fe_symbol *fs;
  c2_const_operand *src2_00;
  c2_operand *src2_01;
  c2_tuple *last;
  c2_insert_fn *insert_fn;
  
  src2 = reader_pop_operand(cell);
  last = cell->tail;
  if (g_opt_windows_app == 0) {
    fs = extern_symbol_lookup_or_create((uint8_t *)"__tls_index");
    pcVar2 = operand_for_fe_symbol(fs);
    if (g_opt_fiber_safe_tls == 0) {
      bVar1 = pcVar2->sym->flags5;
      pcVar2->flags = pcVar2->flags | 0x80;
      pcVar2->sym->flags5 = bVar1 | 4;
    }
    insert_fn = tuple_splice_after;
    src2_00 = operand_new_intconst(0x1004,4,0);
    pcVar3 = tuple_new_binary_temp(0x16f,0x3004,pcVar2,src2_00,insert_fn,last);
    pcVar2 = pcVar3->dst;
    src2_01 = tls_array_operand();
    last = tuple_new_binary_temp(0x16d,0x3004,pcVar2,src2_01,tuple_splice_after,pcVar3);
    pcVar2 = last->dst;
  }
  else {
    extern_symbol_lookup_or_create((uint8_t *)"__tls_index");
    pcVar2 = tls_array_operand();
  }
  pcVar2 = operand_new_mem(0x14c,0x3004,(c2_symbol *)0x0,0,pcVar2,(c2_operand *)0x0,0);
  pcVar2->flags = pcVar2->flags | 0x80;
  pcVar3 = tuple_new_binary_temp(0x16d,0x3004,pcVar2,src2,tuple_splice_after,last);
  cell->tail = pcVar3;
  return;
}

