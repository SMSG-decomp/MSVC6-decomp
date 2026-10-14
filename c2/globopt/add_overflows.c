int __cdecl add_overflows(uint32_t a,uint32_t b,int is_unsigned,int size)

{
  bool bVar1;
  bool bVar2;
  
  if (size == 2) {
    bVar1 = CARRY2((ushort)a,(ushort)b);
    bVar2 = SCARRY2((ushort)a,(ushort)b);
  }
  else if (size < 2) {
    bVar1 = CARRY1((byte)a,(byte)b);
    bVar2 = SCARRY1((byte)a,(byte)b);
  }
  else {
    bVar1 = CARRY2(a._2_2_,b._2_2_) || CARRY2(a._2_2_ + b._2_2_,(ushort)CARRY2((ushort)a,(ushort)b))
    ;
    bVar2 = SCARRY2(a._2_2_,b._2_2_) !=
            SCARRY2(a._2_2_ + b._2_2_,(ushort)CARRY2((ushort)a,(ushort)b));
  }
  if (is_unsigned != 0) {
    bVar2 = bVar1;
  }
  return (uint)bVar2;
}

