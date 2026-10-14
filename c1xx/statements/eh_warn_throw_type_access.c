void __cdecl eh_warn_throw_type_access(c1_catchable_type *ct)

{
  uint uVar1;
  c1_u8 *pcVar2;
  c1_u8 *pcVar3;
  
  if (((ct->flags & 20000) != 0) && ((ct->flags & 0x4000) == 0)) {
    if (ct->path == (int *)0x0) {
      eh_catchable_type_path((int *)ct);
    }
    uVar1 = ct->flags;
    if ((uVar1 & 0x200) == 0) {
      if ((uVar1 & 0x400) != 0) {
        pcVar2 = base_path_text_for_diag((int *)*ct->path,0);
        diag_warning(4,0x29e,pcVar2);
        return;
      }
      if ((uVar1 & 0x800) != 0) {
        pcVar2 = base_path_text_for_diag((int *)*ct->path,0);
        diag_warning(4,0x29f,pcVar2);
        return;
      }
      if ((uVar1 & 0x20) != 0) {
        pcVar2 = base_path_text_for_diag((int *)*ct->path,0);
        diag_warning(4,0x2a2,pcVar2);
      }
    }
    else {
      pcVar2 = base_path_text_for_diag((int *)*ct->path,0);
      if (ct->same_type != (c1_catchable_type *)0x0) {
        pcVar3 = base_path_text_for_diag((int *)*ct->same_type->path,0);
        diag_warning(4,0x2a0,pcVar2,pcVar3);
        return;
      }
    }
  }
  return;
}

