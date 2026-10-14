int __fastcall sr_combine_allowed(c2_operand *a,c2_operand *b,int op)

{
  if (op == 0x16d) {
    return 1;
  }
  if (op == 0x16f) {
    return (uint)((int)(a->u18).lo % (int)(b->u18).lo == 0);
  }
  return 0;
}

