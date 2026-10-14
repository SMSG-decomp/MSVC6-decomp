void __fastcall cxx_eh_number_states_if_needed(c2_function *fn)

{
  uint32_t uVar1;
  
  if ((fn->flags & 0x8000) != 0) {
    uVar1 = cxx_eh_assign_states(fn,0);
    if (uVar1 != 0) {
      cxx_eh_assign_states(fn,1);
    }
  }
  return;
}

