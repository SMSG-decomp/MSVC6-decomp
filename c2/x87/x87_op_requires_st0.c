int __fastcall x87_op_requires_st0(c2_tuple *t)

{
  switch(t->op) {
  case 0x5e:
  case 0x86:
  case 0x87:
  case 0x8a:
  case 0x91:
  case 0x92:
  case 0xd4:
    return 1;
  default:
    return 0;
  }
}

