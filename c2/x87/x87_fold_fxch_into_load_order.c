c2_tuple * __fastcall x87_fold_fxch_into_load_order(c2_tuple *t)

{
  c2_tuple *pos;
  c2_tuple *pcVar1;
  c2_tuple *t_00;
  
  pos = t->prev;
  pcVar1 = t->next;
  t_00 = pos->prev;
  switch(pos->op) {
  case 0x56:
  case 0x60:
  case 0x7f:
  case 0x80:
  case 0x81:
  case 0x82:
  case 0x83:
  case 0x84:
  case 0x94:
    switch(t_00->op) {
    case 0x56:
    case 0x60:
    case 0x7f:
    case 0x80:
    case 0x81:
    case 0x82:
    case 0x83:
    case 0x84:
    case 0x94:
      if ((((pos->src == (c2_operand *)0x0) || (pos->src->kind != '\x01')) &&
          ((t_00->src == (c2_operand *)0x0 || (t_00->src->kind != '\x01')))) &&
         (((t->src->u18).reg)->id == 0x20)) {
        tuple_move_after(pos,t_00);
        tuple_unlink_free(t);
      }
    }
  }
  return pcVar1;
}

