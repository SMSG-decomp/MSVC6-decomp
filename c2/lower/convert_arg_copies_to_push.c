void __fastcall convert_arg_copies_to_push(c2_tuple *call)

{
  uint8_t uVar1;
  c2_operand *pcVar2;
  c2_tuple *t;
  uint32_t uVar3;
  c2_operand *op;
  
  lower_pending_arg_copies(call);
  pcVar2 = call->src->next;
  while (op = pcVar2, op != (c2_operand *)0x0) {
    uVar1 = op->kind;
    pcVar2 = op->next;
    if ((((uVar1 != '\v') && (uVar1 != '\n')) && ((op->flags & 0x20) == 0)) &&
       ((uVar1 != '\x01' || (op->sym->cls != '\x01')))) {
      t = op->sym->def;
      uVar3 = t->op;
      if ((uVar3 == 0x15a) || (uVar3 == 0x16a)) {
        if ((uVar1 == '\x01') && (((op->u18).reg)->cls == '\x01')) {
          lower_arg_push_value(call,op);
        }
        else {
          tuple_remove_src(call,op);
          if ((t->op == 0x15a) && ((t->type & 0xf000) != 0x4000)) {
            t->op = 0xd;
          }
          else {
            tuple_unlink_free(t);
          }
        }
      }
      else if (uVar3 == 400) {
        tuple_unlink_free(t);
        tuple_remove_src(call,op);
      }
    }
  }
  return;
}

