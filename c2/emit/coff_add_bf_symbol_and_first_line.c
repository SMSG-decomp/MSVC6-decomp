void __fastcall
coff_add_bf_symbol_and_first_line
          (uint32_t fn_symbol,uint16_t first_line,uint32_t total_size,int fn_offset)

{
  c2_coff_aux_fndef *pcVar1;
  c2_coff_lineno_chunk *pcVar2;
  uint32_t bf_index;
  c2_coff_lineno_chunk *new_chunk;
  c2_coff_aux_bf *local_4;
  int count;
  c2_coff_lineno_chunk *chunk;
  c2_coff_section_out *out;
  
  out = g_coff_current_section->active;
  chunk = out->lines;
  bf_index = chunk->count;
  out->nlines = out->nlines + 1;
  chunk->count = bf_index + 1;
  chunk->lines[bf_index].offset = fn_symbol;
  count = chunk->count;
  chunk->lines[bf_index].line = 0;
  if (0x31 < count) {
    new_chunk = (*g_coff_alloc_fn)(0x134);
    pcVar2 = chunk->last;
    new_chunk->count = 0;
    new_chunk->last = pcVar2;
    chunk->last = new_chunk;
    out->lines = new_chunk;
  }
  pcVar1 = g_coff_prev_function_aux;
  if ((g_coff_line_info & 1) != 0) {
    if ((g_opt_incremental != 0) && (g_incr_object_not_reusable == 0)) {
      coff_fill_slots_default(g_coff_line_symbol_slot,2);
      g_coff_line_symbol_slot = g_coff_line_symbol_slot + 2;
    }
    bf_index = coff_add_symbol_with_aux
                         (".bf",(uint16_t)_g_coff_cur_code_section,'e',fn_offset,0,&local_4,0);
    local_4->line = first_line;
    local_4->next_bf = 0;
    if (g_coff_prev_bf_aux != (c2_coff_aux_bf *)0x0) {
      g_coff_prev_bf_aux->next_bf = bf_index;
    }
    g_coff_prev_bf_aux = local_4;
    pcVar1 = g_coff_symbol_slots[fn_symbol + 1]->payload;
    pcVar1->tag_index = bf_index;
    pcVar1->total_size = total_size;
    pcVar1->line_offset = 0;
    pcVar1->next_function = 0;
    if (g_coff_prev_function_aux != (c2_coff_aux_fndef *)0x0) {
      g_coff_prev_function_aux->next_function = fn_symbol;
    }
  }
  g_coff_prev_function_aux = pcVar1;
  return;
}

