void __fastcall basic_function_pass(c2_function *fn)

{
  uint32_t nbits;
  int iVar1;
  c2_bitvec **rows;
  uint32_t nbits_00;
  
  arena_reset(4);
  arena_reset(6);
  nbits = basic_number_op18b_sites(fn);
  if (1 < nbits) {
    iVar1 = basic_number_variables();
    if (iVar1 != 0) {
      nbits_00 = iVar1 + 1;
      basic_solve_reaching(fn,nbits);
      basic_compute_block_gen_kill(fn,nbits_00);
      rows = basic_solve_resume_dataflow(fn,nbits,nbits_00);
      basic_init_block_sets(fn,nbits_00,rows);
      basic_solve_liveness(fn,nbits_00);
      basic_mark_live_across_calls(fn,nbits_00,rows);
      arena_reset(4);
      arena_reset(6);
    }
  }
  return;
}

