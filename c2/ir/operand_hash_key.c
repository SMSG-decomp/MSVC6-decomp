uint32_t __fastcall operand_hash_key(c2_operand *op)

{
  if (op != (c2_operand *)0x0) {
    switch(op->kind) {
    case '\0':
      halt_baddata();
    default:
      return op->sym->id;
    case '\x04':
      return (uint32_t)(op->sym->u28).free_next;
    case '\x05':
    case '\x06':
      return ((op->u18).reg)->id;
    case '\a':
      return (uint32_t)(op->u18).reg;
    }
  }
  return 0;
}

