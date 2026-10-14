void __fastcall create_eh_guard_local(uint32_t *bit,c2_symbol **guard)

{
  uint32_t uVar1;
  c2_eh_guard_word *word;
  c2_fe_symbol *fs;
  c2_symbol *pcVar2;
  c2_const_operand *src;
  c2_operand *dst;
  c2_tuple *pcVar3;
  c2_insert_fn *insert_fn;
  
  if ((g_eh_guard_words != (c2_eh_guard_word *)0x0) &&
     ((g_eh_guard_words->next_bit & 0x7fffffff) != 0)) {
    pcVar2 = g_eh_guard_words->local;
    uVar1 = g_eh_guard_words->next_bit * 2;
    g_eh_guard_words->next_bit = uVar1;
    *bit = uVar1;
    *guard = pcVar2;
    return;
  }
  word = arena_alloc(1,0xc);
  word->next = g_eh_guard_words;
  word->next_bit = 1;
  fs = fe_symbol_new_local_cur(2,4,1,1,'\x04',0);
  pcVar2 = fe_symbol_get_storage(fs);
  pcVar3 = g_cxx_eh_init_insert_point;
  insert_fn = tuple_insert_after;
  word->local = pcVar2;
  g_eh_guard_words = word;
  g_eh_guard_local = pcVar2;
  src = operand_new_intconst(0x1004,0,0);
  dst = operand_new_sym(0x14a,0x1004,pcVar2);
  pcVar3 = tuple_new(0x15b,0x1004,dst,src,insert_fn,pcVar3);
  g_cxx_eh_init_insert_point = pcVar3;
  pcVar3->line = 0;
  pcVar3->dst->flags11 = pcVar3->dst->flags11 | 8;
  pcVar2 = word->local;
  *bit = word->next_bit;
  *guard = pcVar2;
  return;
}

