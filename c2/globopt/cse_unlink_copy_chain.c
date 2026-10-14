void __fastcall cse_unlink_copy_chain(c2_symbol *s)

{
  c2_operand *op;
  c2_symbol *sym;
  c2_copy_link *pcVar1;
  c2_cse_expr *pcVar2;
  c2_operand *pcVar3;
  
  pcVar1 = (s->u34).source_links;
  do {
    if (pcVar1 == (c2_copy_link *)0x0) {
      pcVar3 = (c2_operand *)s->def;
      op = (c2_operand *)pcVar3->tag;
      find_next_use_of_dst((c2_tuple *)pcVar3,(c2_operand **)&stack0xfffffffc);
      if (op->kind != '\x02') {
        operand_make_sym(op);
      }
      if (pcVar3->kind != '\x02') {
        operand_make_sym(pcVar3);
      }
      sym = op->sym;
      if (sym->storage->part_next != (c2_symbol *)0x0) {
        symbol_mark_overlapping_parts(sym,(c2_tuple *)0x0);
        return;
      }
      sym->def = (c2_tuple *)0x0;
      return;
    }
    pcVar2 = (pcVar1->copy->u18).expr;
    if (pcVar2 != (c2_cse_expr *)0x0) {
      for (pcVar3 = pcVar2->operands; pcVar3 != (c2_operand *)0x0; pcVar3 = pcVar3->next) {
        if ((pcVar3->kind == '\x01') && (pcVar3->sym == s)) {
          operand_make_sym(pcVar3);
          break;
        }
      }
    }
    pcVar1 = pcVar1->next_of_source;
  } while( true );
}

