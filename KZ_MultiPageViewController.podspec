
Pod::Spec.new do |s|

    s.name = 'KZ_MultiPageViewController'
    s.version = '0.1'
    s.summary = 'iOS Multi Page ViewController.'
    s.homepage = 'https://github.com/KieronZhang/KZ_MultiPageViewController'
    s.license = {:type => 'MIT', :file => 'LICENSE'}
    s.author = {'KieronZhang.' => 'https://github.com/KieronZhang'}
    s.platform = :ios, '8.0'
    s.source = {:git => 'https://github.com/KieronZhang/KZ_MultiPageViewController.git', :tag => s.version, :submodules => true}
    s.xcconfig = {'OTHER_LDFLAGS' => '-ObjC'}
    s.frameworks = 'Foundation'
    s.vendored_frameworks = 'KZ_MultiPageViewController/KZ_MultiPageViewControllerFramework.framework'
    s.requires_arc = true

    s.dependency 'KZ_Categories'
    s.dependency 'KZ_ReuseScrollView'

end
