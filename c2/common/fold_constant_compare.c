int __fastcall
fold_constant_compare
          (int is_signed,int size,uint32_t a_lo,int32_t a_hi,uint32_t b_lo,int32_t b_hi,uint8_t cond
          )

{
  uint32_t uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  bool bVar5;
  uint32_t local_8;
  
  local_8 = b_lo;
  uVar2 = a_lo;
  uVar1 = a_lo;
  uVar3 = a_hi;
  uVar4 = b_hi;
  if (is_signed == 0) {
    switch(size) {
    case 1:
      uVar1 = a_lo & 0xff;
      uVar3 = 0;
      local_8 = b_lo & 0xff;
      uVar4 = 0;
      break;
    case 2:
      uVar1 = a_lo & 0xffff;
      uVar3 = 0;
      local_8 = b_lo & 0xffff;
      uVar4 = 0;
      break;
    case 4:
      uVar3 = 0;
      uVar4 = 0;
    }
  }
  else {
    switch(size) {
    case 1:
      b_lo = (uint32_t)(char)b_lo;
      uVar2 = (int)(char)a_lo;
      a_hi = (int)(char)a_lo >> 0x1f;
      b_hi = (int)b_lo >> 0x1f;
      break;
    case 2:
      b_lo = (uint32_t)(short)b_lo;
      uVar2 = (int)(short)a_lo;
      a_hi = (int)(short)a_lo >> 0x1f;
      b_hi = (int)b_lo >> 0x1f;
      break;
    case 4:
      a_hi = (int)a_lo >> 0x1f;
      b_hi = (int)b_lo >> 0x1f;
    }
  }
  switch(cond) {
  case '\x01':
    if (is_signed == 0) {
      if (uVar1 != local_8) {
        return 0;
      }
      bVar5 = uVar3 == uVar4;
    }
    else {
      if (uVar2 != b_lo) {
        return 0;
      }
      bVar5 = a_hi == b_hi;
    }
    if (bVar5) {
      return 1;
    }
    break;
  case '\x02':
    if (is_signed == 0) {
      if (uVar1 != local_8) {
        return 1;
      }
      if (uVar3 != uVar4) {
        return 1;
      }
    }
    else {
      if (uVar2 != b_lo) {
        return 1;
      }
      if (a_hi != b_hi) {
        return 1;
      }
    }
    break;
  case '\x03':
    if (is_signed == 0) {
      if (uVar3 <= uVar4) {
        if (uVar3 < uVar4) {
          return 1;
        }
        if (uVar1 < local_8) {
          return 1;
        }
      }
    }
    else if (a_hi <= b_hi) {
      if (a_hi < b_hi) {
        return 1;
      }
      if (uVar2 < b_lo) {
        return 1;
      }
    }
    break;
  case '\x04':
    if (is_signed == 0) {
      if (uVar4 <= uVar3) {
        if (uVar4 < uVar3) {
          return 1;
        }
        if (local_8 < uVar1) {
          return 1;
        }
      }
    }
    else if (b_hi <= a_hi) {
      if (b_hi < a_hi) {
        return 1;
      }
      if (b_lo < uVar2) {
        return 1;
      }
    }
    break;
  case '\x05':
    if (is_signed == 0) {
      if (uVar3 <= uVar4) {
        if (uVar3 < uVar4) {
          return 1;
        }
        if (uVar1 <= local_8) {
          return 1;
        }
      }
    }
    else if (a_hi <= b_hi) {
      if (a_hi < b_hi) {
        return 1;
      }
      if (uVar2 <= b_lo) {
        return 1;
      }
    }
    break;
  case '\x06':
    if (is_signed == 0) {
      if (uVar4 <= uVar3) {
        if (uVar4 < uVar3) {
          return 1;
        }
        if (local_8 <= uVar1) {
          return 1;
        }
      }
    }
    else if (b_hi <= a_hi) {
      if (b_hi < a_hi) {
        return 1;
      }
      if (b_lo <= uVar2) {
        return 1;
      }
    }
  }
  return 0;
}

