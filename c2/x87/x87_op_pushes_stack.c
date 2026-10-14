int __fastcall x87_op_pushes_stack(c2_tuple *t)

{
  switch(t->op) {
  case 0x47:
  case 0x49:
  case 0x4a:
  case 0x4d:
  case 0x4f:
  case 0x50:
  case 0x5c:
  case 0x5d:
  case 0x5e:
  case 0xd1:
  case 0xd2:
  case 0xd3:
    return (uint)(t->src->rank == 0);
  default:
    return 0;
  case 0x86:
  case 0x87:
  case 0x8a:
  case 0x91:
  case 0x92:
  case 0xd4:
    return 1;
  }
}

