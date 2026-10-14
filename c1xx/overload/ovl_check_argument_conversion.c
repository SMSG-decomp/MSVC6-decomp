uint __thiscall
ovl_check_argument_conversion
          (c1_ovl_resolution *ctx,c1_conversion *conv,c1_ovl_candidate *cand,int index,c1_node *arg,
          uint code)

{
  char cVar1;
  byte bVar2;
  
  if ((conv->flags4e & 1) != 0) {
    if (((cand->function == (c1_symbol *)0x0) ||
        ((*(byte *)((int)&cand->function->tail + 9) & 0x40) == 0)) ||
       (cand->deduction->param_bytes[index] == '\0')) {
      bVar2 = cand->flags | ((conv->rank & 0xf0) != 0) << 5;
      cand->flags = bVar2;
      if (((byte)conv->rank & 0xf0) == 0x40) {
        cand->flags = bVar2 | 0x10;
        return code;
      }
    }
    else if (((conv->rank & 0xf0) != 0) && ((conv->flags4e & 0x20) == 0)) goto LAB_104133a5;
    return 4;
  }
LAB_104133a5:
  cVar1 = ovl_candidate_remove(ctx,cand,arg);
  return ~-(uint)(cVar1 != '\0') & code;
}

