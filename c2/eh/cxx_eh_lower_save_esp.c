c2_tuple * __fastcall cxx_eh_lower_save_esp(c2_tuple *anchor)

{
  c2_operand *src;
  c2_symbol *sym;
  c2_operand *dst;
  c2_tuple *anchor_00;
  c2_insert_fn *insert_fn;
  
  if (anchor->op != 0x1a5) {
    ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\x86\\ehgen.c",0x317);
  }
  if (((anchor->u20).eh_try)->catch_rec->needs_saved_esp != 0) {
    insert_fn = tuple_insert_after;
    anchor_00 = anchor;
    src = operand_new_hardreg(5,0x1004);
    sym = symbol_get_part(g_cxx_eh_record,0x1004,0,g_cxx_eh_next_offset + -4);
    dst = operand_new_sym(0x14a,0x1004,sym);
    tuple_new(1,0x1004,dst,src,insert_fn,anchor_00);
  }
  return anchor;
}

