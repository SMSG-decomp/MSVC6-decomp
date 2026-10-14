void __fastcall ensure_preheader_value(c2_operand *op,c2_loop *loop)

{
  c2_operand *pcVar1;
  
  pcVar1 = find_rec_value_for_operand(op,loop);
  if (pcVar1 == (c2_operand *)0x0) {
    evaluate_in_preheader(op,loop);
  }
  return;
}

