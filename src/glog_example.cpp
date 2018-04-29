#include <glog/logging.h>

DEFINE_string(input, "", "Input File name");
DEFINE_string(trust_region_strategy, "levenberg_marquardt",
              "Options are: levenberg_marquardt, dogleg.");
DEFINE_string(dogleg, "traditional_dogleg", "Options are: traditional_dogleg,"
              "subspace_dogleg.");
DEFINE_bool(inner_iterations, false, "Use inner iterations to non-linearly "
            "refine each successful trust region step.");
DEFINE_string(blocks_for_inner_iterations, "automatic", "Options are: "
            "automatic, cameras, points, cameras,points, points,cameras");
DEFINE_string(linear_solver, "sparse_schur", "Options are: "
              "sparse_schur, dense_schur, iterative_schur, sparse_normal_cholesky, "
              "dense_qr, dense_normal_cholesky and cgnr.");
DEFINE_bool(explicit_schur_complement, false, "If using ITERATIVE_SCHUR "
            "then explicitly compute the Schur complement.");
DEFINE_string(preconditioner, "jacobi", "Options are: "
              "identity, jacobi, schur_jacobi, cluster_jacobi, "
              "cluster_tridiagonal.");
DEFINE_string(visibility_clustering, "canonical_views",
              "single_linkage, canonical_views");
DEFINE_string(sparse_linear_algebra_library, "suite_sparse",
              "Options are: suite_sparse and cx_sparse.");
DEFINE_string(dense_linear_algebra_library, "eigen",
              "Options are: eigen and lapack.");
DEFINE_string(ordering, "automatic", "Options are: automatic, user.");
DEFINE_bool(use_quaternions, false, "If true, uses quaternions to represent "
            "rotations. If false, angle axis is used.");
DEFINE_bool(use_local_parameterization, false, "For quaternions, use a local "
            "parameterization.");
DEFINE_bool(robustify, false, "Use a robust loss function.");
DEFINE_double(eta, 1e-2, "Default value for eta. Eta determines the "
             "accuracy of each linear solve of the truncated newton step. "
             "Changing this parameter can affect solve performance.");
DEFINE_int32(num_threads, 1, "Number of threads.");
DEFINE_int32(num_iterations, 5, "Number of iterations.");
DEFINE_double(max_solver_time, 1e32, "Maximum solve time in seconds.");
DEFINE_bool(nonmonotonic_steps, false, "Trust region algorithm can use"
            " nonmonotic steps.");
DEFINE_double(rotation_sigma, 0.0, "Standard deviation of camera rotation "
              "perturbation.");
DEFINE_double(translation_sigma, 0.0, "Standard deviation of the camera "
              "translation perturbation.");
DEFINE_double(point_sigma, 0.0, "Standard deviation of the point "
              "perturbation.");
DEFINE_int32(random_seed, 38401, "Random seed used to set the state "
             "of the pseudo random number generator used to generate "
             "the pertubations.");
DEFINE_bool(line_search, false, "Use a line search instead of trust region "
            "algorithm.");
DEFINE_string(initial_ply, "", "Export the BAL file data as a PLY file.");
DEFINE_string(final_ply, "", "Export the refined BAL file data as a PLY "
              "file.");

/*
 http://rpg.ifi.uzh.ch/docs/glog.html

GLOG_vmodule=1

GLOG_minloglevel=
GLOG_v=1


 GLOG_v=7 GLOG_logtostderr=1 ./glog_example

GLOG_logtostderr=1
	Log messages to stderr instead of logfiles

 
GLOG_stderrthreshold=0
	levels INFO, WARNING, ERROR, and FATAL are 0, 1, 2, and 3, respectively.
	
	
If the Google gflags library isn't installed, you set flags via environment variables, prefixing the flag name with "GLOG_", e.g.
   GLOG_logtostderr=1 ./your_application
   
   
 
 */
#include <iostream>
#include <iostream>
int main(int argc, char* argv[]) {
	// Initialize Google's logging library.
	google::InitGoogleLogging(argv[0]);
	google::SetCommandLineOption("GLOG_minloglevel", "0");
	google::SetCommandLineOption("GLOG_minloglevel", "0");

	FLAGS_log_dir = "glog";

	int num_cookies=10;
	LOG(INFO) << "Found " << num_cookies << " cookies";
	LOG(ERROR) << "ERROR occured ";
	LOG(INFO) << "file";
	// Most flags work immediately after updating values.
	FLAGS_logtostderr = 1;
	LOG(INFO) << "stderr";
	//FLAGS_logtostderr = 0;
	// This won't change the log destination. If you want to set this
	// value, you should do this before google::InitGoogleLogging .
	LOG(INFO) << "the same file";
	
	VLOG(1) << "I'm printed when you run the program with --v=1 or higher";
	
	DLOG(INFO) << "Found cookies";
}

