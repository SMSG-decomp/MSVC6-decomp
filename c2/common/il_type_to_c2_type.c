uint __fastcall il_type_to_c2_type(short kind,uint size)

{
  ushort uVar1;
  
  uVar1 = (ushort)(size >> 0x10);
  switch(kind) {
  case 0:
    return (uint)uVar1 << 0x10;
  case 2:
    return size | 0x2000;
  case 3:
  case 4:
  case 0xb:
    return CONCAT22(uVar1,g_ptr_type);
  case 5:
  case 10:
    break;
  case 6:
    return CONCAT22(uVar1,(0xfff < (int)size) - 1 & (ushort)size) | 0x5000;
  case 7:
    size = 4;
  case 1:
    return size | 0x1000;
  default:
    ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\getattr.c",0x26b);
  }
  if (size != 10) {
    return size | 0x4000;
  }
  return 0x400a;
}

