void __fastcall optimize_loop_induction_variables(c2_loop *loop,c2_function *fn)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  if ((loop->guard->flags & 0x2000000) == 0) {
    canonicalize_loop_neg_sub(loop);
    collect_iv_excluded_symbols(loop);
    find_basic_induction_variables(loop);
    uVar1 = widen_iv_subfield_uses(loop);
    build_iv_def_use_lists(loop);
    iVar2 = analyze_loop_exit_test(loop,fn);
    if (iVar2 != 0) {
      g_in_iv_optimization = 1;
      uVar3 = merge_parallel_induction_variables(loop,fn);
      strength_reduce_loop((int)loop,fn,(c2_operand *)(uVar1 | uVar3));
      cleanup_preheader_after_sr(loop,fn);
      record_preheader_iv_inits(loop);
      remove_dead_iv_code(loop,fn);
      convert_loop_stores_to_block_op(loop,fn);
      build_iv_def_use_lists(loop);
      merge_parallel_induction_variables(loop,fn);
      build_iv_def_use_lists(loop);
      replace_loop_exit_tests(loop,fn);
      remove_dead_iv_code(loop,fn);
      build_iv_def_use_lists(loop);
      strength_reduce_address_operands(loop);
      build_iv_def_use_lists(loop);
      convert_exit_test_to_countdown(loop,fn);
      build_iv_def_use_lists(loop);
      replace_iv_with_final_value(loop,fn);
      record_iv_update_clones(loop);
      fold_child_loop_iv_reinit(loop);
      delete_empty_loop(loop,fn);
      recse_preheader(loop,fn);
      rewrite_loop_guard_compare(loop);
      g_in_iv_optimization = 0;
    }
    finish_loop_iv_optimization();
  }
  return;
}

