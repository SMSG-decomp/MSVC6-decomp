void __fastcall emit_set_frame_operand_size(c2_operand *op)

{
  c2_symbol *pcVar1;
  
  if (op->op == 0x14a) {
    pcVar1 = op->sym;
  }
  else {
    pcVar1 = op->base_sym;
  }
  if (pcVar1 != (c2_symbol *)0x0) {
    pcVar1 = pcVar1->storage;
    switch(pcVar1->cls) {
    case '\x03':
      if ((pcVar1->flags5 & 0x20) != 0) {
        tail_set_0c_if_positive((pcVar1->u28).frame_home,op);
        return;
      }
      break;
    case '\x04':
    case '\x05':
    case '\a':
    case '\b':
      if (0 < pcVar1->fe->offset) {
        op->rank = 4;
      }
      break;
    case '\x06':
      tail_set_0c_if_positive(pcVar1->offset,op);
      return;
    default:
      tail_set_0c_if_positive((int32_t)op,op);
      return;
    }
  }
  return;
}

