void __fastcall emit_chkesp_check(c2_tuple *call)

{
  c2_operand *pcVar1;
  c2_tuple *pcVar2;
  c2_tuple *pcVar3;
  c2_fe_symbol *sym;
  c2_operand *pcVar4;
  uint8_t call_conv;
  c2_operand *pcVar5;
  c2_insert_fn *insert_fn;
  
  if (call->src->kind != '\x04') {
    pcVar4 = (c2_operand *)0x0;
    pcVar5 = call->src->next;
    for (pcVar1 = pcVar5; pcVar1 != (c2_operand *)0x0; pcVar1 = pcVar1->next) {
      if (pcVar1->sym->def->op == 400) {
        return;
      }
    }
    pcVar3 = call;
    if (pcVar5 != (c2_operand *)0x0) {
      do {
        if ((pcVar5->flags & 0x20) == 0) {
          pcVar4 = pcVar5;
        }
        pcVar5 = pcVar5->next;
      } while (pcVar5 != (c2_operand *)0x0);
      if (pcVar4 != (c2_operand *)0x0) {
        pcVar3 = pcVar4->sym->def;
      }
    }
    if ((pcVar3->op == 0x15a) && ((pcVar3->src->type & 0xf000) == 0x4000)) {
      pcVar3 = pcVar3->prev->prev;
      if (pcVar3->op != 0x32) {
        ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\x86\\lower.c",0x325);
      }
      if ((pcVar3->dst->u18).reg != g_reg_symbols + 5) {
        ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\x86\\lower.c",0x326);
      }
    }
    pcVar5 = (c2_operand *)0x0;
    pcVar1 = operand_new_hardreg(5,0x1004);
    pcVar2 = emit_op_before_with_parts(1,0x1004,pcVar1,pcVar5,pcVar3);
    pcVar3 = call->next;
    pcVar1 = operand_new_hardreg(5,0x1004);
    pcVar3 = emit_op_before_with_parts(0x2f,0x1004,pcVar2->dst,pcVar1,pcVar3);
    pcVar1 = pcVar3->dst;
    insert_fn = tuple_insert_after;
    call_conv = '\x04';
    sym = fe_symbol_lookup_name("__chkesp");
    pcVar5 = operand_new_codeaddr(0x153,sym);
    pcVar3 = tuple_new_call(0xe,0x1004,(c2_operand *)0x0,pcVar5,call_conv,insert_fn,pcVar3);
    tuple_append_src(pcVar3,pcVar1);
    pcVar1 = operand_new_hardreg(5,0x1004);
    tuple_append_src(pcVar3,pcVar1);
  }
  return;
}

