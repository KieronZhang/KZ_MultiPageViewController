
Pod::Spec.new do |s|

    s.name = 'KZ_MultiPageViewController'
    s.version = '0.1.2'
    s.summary = 'iOS Multi Page ViewController.'
    s.homepage = 'https://github.com/KieronZhang/KZ_MultiPageViewController'
    s.license = {:type => 'MIT', :file => 'LICENSE'}
    s.author = {'KieronZhang' => 'https://github.com/KieronZhang'}

    s.source = {:git => 'https://github.com/KieronZhang/KZ_MultiPageViewController.git', :tag => s.version, :submodules => true}
    s.xcconfig = {'OTHER_LDFLAGS' => '-ObjC'}
    s.requires_arc = true

    s.ios.frameworks = 'Foundation', 'UIKit'

    s.ios.deployment_target = '8.0'

    s.ios.vendored_frameworks = 'KZ_MultiPageViewController/KZ_MultiPageViewController_iOS.framework'

    s.dependency 'KZ_Categories'
    s.dependency 'KZ_ReuseScrollView'

end
