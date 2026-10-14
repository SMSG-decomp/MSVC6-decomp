int __fastcall operand_fits_instruction(c2_tuple *t,int which,c2_operand *op)

{
  uint uVar1;
  c2_operand *opnd2;
  uint32_t local_10 [4];
  
  uVar1 = t->op;
  if (0x3b < uVar1) {
    switch(uVar1) {
    case 0x10e:
    case 0x10f:
    case 0x111:
    case 0x112:
      goto switchD_1071ea2b_caseD_e;
    default:
switchD_1071ea2b_caseD_f:
      if (which == 1) {
        opnd2 = t->src->next;
      }
      else {
        opnd2 = op;
        if (which == 2) {
          op = t->src;
        }
      }
      zero_16_bytes(local_10);
      operand_constraints_by_opcode(t,t->dst,op,opnd2,local_10);
      return (uint)(local_10[0] == 0);
    }
  }
  if (uVar1 != 0x3b) {
    switch(uVar1) {
    case 0xe:
    case 0x35:
    case 0x37:
    case 0x38:
      break;
    default:
      goto switchD_1071ea2b_caseD_f;
    }
  }
switchD_1071ea2b_caseD_e:
  return 0;
}

