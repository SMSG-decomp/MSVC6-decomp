uint32_t __fastcall temp_operand_piece_mismatch(c2_operand *op)

{
  if ((((op->u18).reg)->storage == op->sym->storage) && (((op->u18).reg)->offset == op->sym->offset)
     ) {
    return 0;
  }
  return 1;
}

