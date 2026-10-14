void __fastcall cxx_eh_new_int2_init_record(c2_function *unused,c2_init **out)

{
  c2_init *pcVar1;
  
  pcVar1 = alloc_init_record(1);
  *out = pcVar1;
  (pcVar1->u18).repeat = 2;
  (pcVar1->u08).data.size = 4;
  (pcVar1->u08).data.value_kind = 2;
  (pcVar1->u08).header.offset = 0;
  return;
}

