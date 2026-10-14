void __fastcall emit_set_frame_operand_size_case_3(c2_operand *opnd,c2_symbol *storage)

{
  if ((storage->flags5 & 0x20) != 0) {
    tail_set_0c_if_positive((storage->u28).frame_home,opnd);
    return;
  }
  return;
}

